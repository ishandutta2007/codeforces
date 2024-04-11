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
string s,ans;
char ch;
int n;
bool ok;
int mas[5000],np;
int main() {
    cin>>s;
    n=s.size();
    int num=0;
    ch='Z';
    for (int i=0;i<n;i++){
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            ch='Z';
            num=0;
            ok=0;
            continue;
        }
        if (num==0){
            num++;
            ch=s[i];
            continue;
        }
        num++;
        if (s[i]!=ch)
            ok=1;
        if (num>=3 && ok){
            mas[++np]=i;
            ok=0;
            num=1;
            ch=s[i];
        }
    }
    mas[++np]=n;
    for (int i=0;i<np;i++){
        for (int j=mas[i];j<mas[i+1];j++)
            ans+=s[j];
        if (i<np-1)
            ans+=" ";
    }
    cout<<ans<<endl;
	return 0;
}