#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
#define X first
#define Y second

const int inf=1e9+10;
const int N=1e5+10;


int ra[3],no,nc,test;
ii res[3];
int ao[N][3],ac[N][3];
vector <ii> imp[8][N];
int a[3];


struct BIT{
        int b[N];
        void reset(){
                for(int i=0;i<N;i++) b[i]=inf;
        }
        void update(int x,int val){
                while (x<N){
                        b[x]=min(b[x],val);
                        x+=x&-x;
                }
        }
        int get(int x){
                int ans=inf;
                while (x){
                        ans=min(ans,b[x]);
                        x-=x&-x;
                }
                return ans;
        }
}mbit;
struct ques{
        int x,y,pos;
        ques(int _x=0,int _y=0,int _pos=0){
                x=_x;
                y=_y;
                pos=_pos;
        }
};
vector <ques> qu[8][N];
int ans[N];
set <ii> mse;

void putin(int* a){
        int mask2=0,mask1=0;
        for(int j=2;j>=0;j--){
                if (res[j].X<=a[j]&&a[j]<=res[j].Y) mask1|=1<<j;
                else mask2|=(a[j]>res[j].Y)<<j;
        }
        if (mask1==7){
                cout<<"INCORRECT";
                exit(0);
        }

        int v[3];
        for(int u1=0;u1<8;u1++) if ((u1&(7^mask1))==mask2){
                for(int j=0;j<3;j++) v[j]=a[j];
                for(int j=0;j<3;j++){
                        if (u1&(1<<j)) v[j]=max(v[j]-res[j].Y,0);
                        else v[j]=max(res[j].X-v[j],0);
                }
                imp[u1][v[0]].push_back(ii(v[1],v[2]));
        }
}
void putout(int *a,int idx){
        
        int mask2=0,mask1=0;
        for(int j=2;j>=0;j--){
                if (res[j].X<=a[j]&&a[j]<=res[j].Y) mask1|=1<<j;
                else mask2+=(a[j]>res[j].Y)<<j;
        }
        //cout<<"?"<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<mask1<<" "<<mask2<<'\n';
        if (mask1==7){
                ans[idx]=-1;
                return;
        }
        int u1=mask2|mask1;
        int v[3];
        for(int j=0;j<3;j++) v[j]=a[j];
        for(int j=0;j<3;j++){
                if (u1&(1<<j)) v[j]=max(v[j]-res[j].Y,0);
                else v[j]=max(res[j].X-v[j],0);
        }
//        cout<<"ask "<<idx<<" "<<u1<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<'\n';
        qu[u1][v[0]].push_back(ques(v[1],v[2],idx));
}
void modified(ii info){
        auto iteR=mse.lower_bound(ii(info.X,-inf));
        if (iteR!=mse.end()&&iteR->X==info.X){
                info.Y=min(info.Y,iteR->Y);
                mse.erase(iteR);
        }
        auto iteL=mse.lower_bound(info);
        if (iteL!=mse.begin()){
                iteL--;
                if (iteL->Y<=info.Y) return;
        }
        while (!mse.empty()){
                iteR=mse.lower_bound(info);
                if (iteR==mse.end()) return;
                if (info.Y<=iteR->Y) mse.erase(iteR); 
                else break;
        }
        mse.insert(info);
}
void modified2(ii info){
        mbit.update(info.X+1,info.Y);
}
bool check(ii info){
        /*
        auto iteR=mse.upper_bound(ii(info.X,inf));
        if (iteR==mse.begin()) return 1;
        iteR--;
        return info.Y<iteR->Y;
        */
        return info.Y<mbit.get(info.X+1);
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>ra[0]>>ra[1]>>ra[2]>>no>>nc>>test;
        for(int i=0;i<3;i++) 
                res[i]=ii(inf,-1);
        
        for(int i=1;i<=no;i++){
                for(int j=0;j<3;j++){
                        cin>>ao[i][j];
                        res[j].Y=max(res[j].Y,ao[i][j]);
                        res[j].X=min(res[j].X,ao[i][j]);
                }
        }
        //for(int i=0;i<3;i++) cout<<res[i].X<<"<->"<<res[i].Y<<'\n';
        for(int i=1;i<=nc;i++){
                for(int j=0;j<3;j++) cin>>ac[i][j];
                putin(ac[i]);
        }
        for(int j=1;j<=test;j++){
                for(int i=0;i<3;i++) cin>>a[i];
                putout(a,j);
        }
        for(int mask=0;mask<8;mask++){
                mbit.reset();
                for(int i=0;i<=ra[0];i++){
                        for(auto info:imp[mask][i]) {
                               //cout<<"call "<<mask<<" "<<i<<" "<<info.X<<" "<<info.Y<<'\n';
                                modified2(info);
                        }
                        for(auto info:qu[mask][i]){
                                //cout<<"try "<<mask<<" "<<i<<" "<<info.x<<" "<<info.y<<'\n';
                                if (!check(ii(info.x,info.y)))
                                        ans[info.pos]=1;
                        }
                }
        }
        cout<<"CORRECT\n";
        for(int i=1;i<=test;i++){
                if (ans[i]==-1) cout<<"OPEN\n";
                if (ans[i]==1) cout<<"CLOSED\n";
                if (ans[i]==0) cout<<"UNKNOWN\n";
        }
}