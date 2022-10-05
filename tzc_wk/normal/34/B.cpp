#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
int f[MAXN],ans=0;
int main () {
	int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)	cin>>f[i];
    sort(f,f+n);
    for(int i=0;i<m;i++){
        if (f[i]>=0)
            break;        
        ans+=f[i];
    }
    cout<<-ans<<endl;
    return 0;
}