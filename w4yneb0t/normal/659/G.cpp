#include<bits/stdc++.h>
typedef int inti;
#define int long long
#define f first
#define s second
#define mod 1000000007

using namespace std;

inti main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <inti> h (n+2);
    for (int i=1; i<n+1; i++){
        cin >> h[i];
    }
    h[0]=h[1];
    h[n+1]=h[n];
    int anz=0;
    int wf=0;
    inti mih, mah;
    for (int i=1; i<n+1; i++){
       // cout << wf << " " << anz << endl;
        mih=max(h[i]-h[i-1]+1,max(h[i]-h[i+1]+1, 1));
        int mi=mih;
        int nwf=(wf*(h[i]-mih))%mod;
        //cout << nwf << endl;
        mih=max(h[i]-h[i+1]+1, 1);
        nwf=(nwf+h[i]-mih)%mod;
        //cout << nwf << endl;
        mih=max(h[i]-h[i-1]+1, 1);
        anz=(anz+(h[i]-mih)*wf)%mod;
        //cout << anz << endl;
        anz=(anz+h[i]-1)%mod;
         //cout << anz << endl;
        wf=nwf;
        nwf=0;
    }
    cout << anz << "\n";
}