#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=70005;
map<int,int>M[15];
void add (string s, int x){
    for (int l=0;l<9;l++){
        int xx=0;
        for (int r=l;r<9;r++){
            xx=xx*10+s[r]-'0';
            M[r-l+1][xx]+=x;
        }
    }
}
int n;
string s[N];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++){
        char ch;
        for (int j=0;j<9;j++){
            ch=getchar();
            while (!('0'<=ch && ch<='9'))
                ch=getchar();
            s[i]+=ch;
        }
        add(s[i],1);
    }
    for (int i=1;i<=n;i++){
        add(s[i],-1);
        int S=100;
        string ans="",pas;
        for (int l=0;l<9;l++){
            int xx=0;
            pas="";
            for (int r=l;r<9 && r<l+S-1;r++){
                xx=xx*10+s[i][r]-'0';
                pas+=s[i][r];
                if (M[r-l+1][xx]==0){
                    S=r-l+1;
                    ans=pas;
                }
            }
        }
        add(s[i],1);
        cout<<ans<<endl;
    }
	return 0;
}