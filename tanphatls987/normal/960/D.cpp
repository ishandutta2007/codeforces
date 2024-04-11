#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

long long sh[62];

int mlog2(long long pos){
        int ans=0;
        while (pos) ans++,pos>>=1;
        return ans-1;
}
int main(){
        int test;
        cin>>test;
        while (test--){
                int type;
                long long pos,shift;
                cin>>type>>pos;
                int lv=int(mlog2(pos));
                if (type==3){
                        pos=((1LL<<lv)+(pos-sh[lv]+(1LL<<lv))%(1LL<<lv));
                        for(int i=lv;i>=0;i--,pos>>=1){
                                long long st=1LL<<i;
                                cout<<(pos+sh[i])%(1LL<<i)+st<<" ";
                        }
                        cout<<'\n';
                        continue;
                }
                cin>>shift;
                if (type==1){
                        sh[lv]=(sh[lv]+(1LL<<lv)-shift%(1LL<<lv))%(1LL<<lv);
                }
                if (type==2){
                        shift%=(1LL<<lv);
                        for(int i=lv;i<62;i++){
                                sh[i]=(sh[i]+(1LL<<i)-shift%(1LL<<i))%(1LL<<i);
                                shift*=2;
                        }
                }
        }
}