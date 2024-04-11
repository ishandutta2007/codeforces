#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
const int alp=26;

int q[N];
vector <int> v[N*alp];
int f[N][N];
int t[N][N];
string s;

bool minimize(int &x,int y){
        if (x>y) x=y;else return 0;
        return 1;
}
int main(){
        cin>>s;
        int n=s.length();
        int logn=log2(n);
        for(int i=1;i<=n;i++) f[i][i]=1;

        for(int len=0;len<=n-(1<<logn)+1;len++){
                ///move in same layer
                for(int i=len;i<n;i++){
                        int mask=i-len;
                        for(int j=0;j<logn;j++) if (!(mask&(1<<j))){
                                int ni=i+(1<<j),nmask=mask|(1<<j);
                                if (ni>n) continue;
                                if (minimize(f[ni][nmask],f[i][mask]))
                                        t[ni][nmask]=j;
                        }
                        v[f[i][mask]].push_back(i);
                }
                if (len==n-(1<<logn)+1) break;
                //for(int i=len;i<=n;i++) cout<<i<<" "<<len<<" "<<i-len<<" "<<f[i][i-len]<<" "<<t[i][i-len]<<'\n';
                ///move layer into queue

                int top=1,bot=0;
                for(int i=0;bot<n-len&&i<N*alp;i++) if (!v[i].empty()){       
                        for(auto pos:v[i])
                                q[++bot]=pos;
                        v[i].clear();
                }
                ///move from layer len to len+1
                int nc=0;
                while (top<=bot){
                        int old_top=top;
                        while (top<=bot&&f[q[top]][q[top]-len]==f[q[old_top]][q[old_top]-len]) top++;
                        ///
                        for(int i=old_top;i<top;i++){
                                int pos=q[i];
                                v[s[pos]-'a'].push_back(pos+1);
                        }
                        for(int i=0;i<alp;i++) if (!v[i].empty()){
                                nc++;
                                for(auto pos:v[i]){
                                        f[pos][pos-len-1]=nc;
                                        t[pos][pos-len-1]=-1;
                                }
                                v[i].clear();
                        }
                        ///
                }
        }
        string ans;
        int pos=n,len=(1<<logn)-1;
        while (pos){
                int use=t[pos][len];
                if (use==-1) ans.push_back(s[--pos]);
                else pos-=1<<use,len-=1<<use;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
}