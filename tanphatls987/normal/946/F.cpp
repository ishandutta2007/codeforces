#include <bits/stdc++.h>

using namespace std;

const int N=1e2+5;
const int MOD=1e9+7;
const int alp=2;

int n,m;
string s;;
struct matrix{
        int n0,n1,a[N][N];
        void reset(){
                memset(a,0,sizeof(a));
        }
        matrix(int n0=0,int n1=0):n0(n0),n1(n1){
                reset();
        }
};
matrix unit(int n){
        matrix ans(n,n);
        for(int i=0;i<n;i++) ans.a[i][i]=1;
        return ans;
}
matrix operator* (matrix a,matrix b){
        assert(a.n1==b.n0);
        matrix ans(a.n0,b.n1);
        for(int i=0;i<a.n0;i++)
                for(int j=0;j<b.n1;j++)
                        for(int k=0;k<a.n1;k++)
                                ans.a[i][j]=(ans.a[i][j]+1LL*a.a[i][k]*b.a[k][j])%MOD;
        return ans;
}

matrix mb[N];
int T[N],trans[N][2];
int solve(){
        int n=s.length();
        for(int len=2;len<=n;len++){
                T[len]=T[len-1];
                while (T[len]&&s[T[len]]!=s[len-1]) T[len]=T[T[len]];
                if (s[T[len]]==s[len-1]) T[len]++;
        }

        s.push_back('@');
        for(int len=0;len<=n;len++)
                for(int use=0;use<alp;use++){
                        int nlen=len;
                        while (nlen&&s[nlen]!='0'+use) nlen=T[nlen];
                        if (s[nlen]=='0'+use) nlen++;
                        trans[len][use]=nlen;
                }
        for(int i=0;i<alp;i++) mb[i]=matrix(n+2,n+2);

        for(int j=0;j<alp;j++){
                for(int i=0;i<n+1;i++) mb[j].a[i][i]=1;
                mb[j].a[n+1][n+1]=2;
        }
        for(int use=0;use<alp;use++)
                for(int len=0;len<=n;len++){
                        mb[use].a[len][trans[len][use]]++;
                        if (trans[len][use]==n) mb[use].a[len][n+1]++;
                }
        for(int i=2;i<=m;i++)
                mb[i]=mb[i-1]*mb[i-2];
/*        for(int i=0;i<=m;i++){
                cout<<i<<'\n';
                for(int j=0;j<n+2;j++)
                        for(int k=0;k<n+2;k++) cout<<mb[i].a[j][k]<<" \n"[k==n+1];
        }*/
        return mb[m].a[0][n+1];
}
int main(){
        cin>>n>>m>>s;
        cout<<solve();
}