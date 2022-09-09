#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+10;
string s;
string rez;
vector<pii>ones;
int n,maxx,bad[maxn];
int inf=1e9+10;

void find_intervals(){


    int lp=-1;
    int rp=-1;
    int curr=0;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){

            if(curr==0){
                curr++;
                ones.pb({i,i});
            }
            else ones.back().ss++;

        }
        else curr=0;
    }

    ///for(int i=0;i<ones.size();i++)printf("%d %d ASd\n",ones[i].ff,ones[i].ss);

}

void mark_bad(){

    maxx=inf;

    int prv=0;
    for(int i=0;i<ones.size();i++){

        if(i==0){
            maxx=min(maxx,ones[i].ff);
            if(ones[i].ff-1>=0)bad[ones[i].ff-1]=1;
        }
        else{

            maxx=min(maxx,ones[i].ff-prv-1-1);
            if(ones[i].ff-prv-1-1-1>=0)bad[ones[i].ff-prv-1-1-1]=1;

        }

        prv=ones[i].ss;
    }

    prv=0;
    for(int i=0;i<ones.size();i++){

        if(i==ones.size()-1){
            maxx=min(maxx,n-ones[i].ss-1);
            if(n-ones[i].ss-1-1>=0)bad[n-ones[i].ss-1-1]=1;
        }
        else{}

        prv=ones[i].ff;
    }

    for(int i=maxx+1;i<=n;i++)bad[i]=1;

}

bool go(int x){

    rez.clear();
    rez.resize(n);

    int prv=-1;
    for(int i=0;i<ones.size();i++){

        int l=ones[i].ff-x;
        int r=ones[i].ss;
        rez[r+1]='_';

        for(int j=l;j<=r;j++)rez[j]='#';


        int curr=0;
        for(int j=l-1;j>prv;j--){

            if(curr==0)rez[j]='_';
            else rez[j]='#';

            curr++;
            if(curr==x+1)curr=0;
        }
        if(rez[prv+1]=='_')swap(rez[prv+1],rez[prv+2]);

        prv=r+1;
    }


    int curr=1;
    for(int i=n-x-1;i>ones.back().ss+1;i--){

        if(curr==0)rez[i]='_';
        else rez[i]='#';

        curr++;
        if(curr==x+1)curr=0;
    }
    if(rez[ones.back().ss+2]=='_')swap(rez[ones.back().ss+2],rez[ones.back().ss+3]);

    for(int i=n-x;i<n;i++)rez[i]='_';

    return true;

}

bool go0(){

    if(s[0]=='_')return false;
    if(s.back()=='_')return false;

    int curr=0;
    for(int i=0;i<n;i++){

        if(s[i]=='_'){
            curr++;
            if(curr>1)return false;
        }
        else curr=0;

    }
    rez=s;
    return true;
}

bool go1(){

    int x=1;

    rez.clear();
    rez.resize(n);

    int prv=-1;
    for(int i=0;i<ones.size();i++){

        int l=ones[i].ff-x;
        int r=ones[i].ss;
        rez[r+1]='_';

        for(int j=l;j<=r;j++)rez[j]='#';


        int curr=0;
        for(int j=l-1;j>prv;j--){

            if(curr==0)rez[j]='_';
            else rez[j]='#';

            curr++;
            if(curr==x+1)curr=0;
        }
        if(rez[prv+1]=='_')return false;

        prv=r+1;

        ///cout<<rez<<endl;
    }


    int curr=1;
    for(int i=n-x-1;i>ones.back().ss+1;i--){

        if(curr==0)rez[i]='_';
        else rez[i]='#';

        curr++;
        if(curr==x+1)curr=0;
    }
    if(rez[ones.back().ss+2]=='_')return false;

    for(int i=n-x;i<n;i++)rez[i]='_';

    return true;

}

void ispis(){

    vector<pii>bla;
    int lp=-1;
    int rp=-1;
    int curr=0;
    for(int i=0;i<n;i++){
        if(rez[i]=='#'){

            if(curr==0){
                curr++;
                bla.pb({i,i});
            }
            else bla.back().ss++;

        }
        else curr=0;
    }

    printf("%d\n",bla.size());
    for(int i=0;i<bla.size();i++)printf("%d ",bla[i].ss-bla[i].ff+1);
    printf("\n");
}

int main(){

    cin>>s;
    n=s.size();

    find_intervals();

    if(ones.size()==0){
        printf("0\n");
        return 0;
    }

    mark_bad();

    ///for(int i=0;i<=n;i++)printf("%d %d BAD\n",i,bad[i]);

    int e=0;
    for(int i=n;i>1;i--){

        if(bad[i])continue;

        if(go(i)){
            e=1;
            break;
        }

    }

    if(e){
        ispis();
        return 0;
    }

    if(bad[1]==0){
        if(go1()){
            ispis();
            return 0;
        }
    }

    if(bad[0]==0){
        if(go0()){
            ispis();
            return 0;
        }
    }

    printf("-1\n");

return 0;
}