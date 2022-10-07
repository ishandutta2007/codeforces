#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
string s;
int n,k;
int a[1000005];
int mas[30];
int x;
int main() {
    cin>>n>>k;
    cin>>s;
    s="#"+s;
    for (int i=n;i>=1;i--){
        if (mas[s[i]-'A']==0)
            a[i]--;
        mas[s[i]-'A']=1;
    }
    for (int i=0;i<26;i++)
        mas[i]=0;
    for (int i=1;i<=n;i++){
        if (mas[s[i]-'A']==0)
            x++;
        x+=a[i-1];
        mas[s[i]-'A']=1;
        if (x>k){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}