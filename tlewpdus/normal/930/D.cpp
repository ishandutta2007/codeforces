#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
vector<pii> odd, eve;
int Mx = 400010;

int maxi[400100], mini[400100];
int maxi2[400100], mini2[400100];

int calc(int h, int l) {
    if (l>=h) return 0;
    return (h-l)/2;
}
ll solve(vector<pii>&vec, int s) {
    int i;

    //printf("!!!!\n");

    for (i=0;i<Mx;i++) maxi2[i] = maxi[i] = -1, mini2[i] = mini[i] = Mx;
    int p = s;
    sort(vec.begin(),vec.end());
    int cmax = -1, cmin = Mx;
    for (i=0;i<vec.size();i++) {
        //printf("%d, %d\n",vec[i].first,vec[i].second);
        for (;p<vec[i].first;p+=2) {
            maxi[p]=max(maxi[p],cmax);
            mini[p]=min(mini[p],cmin);
        }
        cmax = max(cmax,vec[i].second);
        cmin = min(cmin,vec[i].second);
    }
    for (;p<Mx;p+=2) {
        maxi[p]=max(maxi[p],cmax);
        mini[p]=min(mini[p],cmin);
    }

    p = Mx-s;
    cmax = -1, cmin = Mx;
    for (i=(int)vec.size()-1;i>=0;i--) {
        for (;p>vec[i].first;p-=2) {
            maxi2[p]=max(maxi2[p],cmax);
            mini2[p]=min(mini2[p],cmin);
        }
        cmax = max(cmax,vec[i].second);
        cmin = min(cmin,vec[i].second);
    }
    for (;p>=0;p-=2) {
        maxi2[p]=max(maxi2[p],cmax);
        mini2[p]=min(mini2[p],cmin);
    }

    ll res = 0;
    for (p=s;p<Mx;p+=2) {
        ll v = (ll)calc(min(maxi[p],maxi2[p]), max(mini[p],mini2[p]));
       // if (v) printf("%d! : %lld\n",p,v);
       // if (p==200003) {
       //     printf("%d, %d, %d, %d\n",maxi[p],maxi2[p],mini[p],mini2[p]);
       // }
        res += v;
    }
    return res;
}

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        if ((a+b)%2) odd.push_back(pii(b-a+200001,b+a+200001));
        else eve.push_back(pii(b-a+200001,b+a+200001));
    }
    ll res = solve(odd,1)+solve(eve,0);
    printf("%lld\n",res);

    return 0;
}