#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
     double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
     double vmax, t;
    cin>>vmax>>t;
     double vx, vy, wx,wy;
    cin>>vx>>vy>>wx>>wy;
     double ans = 0;
     double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
     double x =x2-x1;
     double y = y2-y1;
    if ((x*x<0.5)&&(y*y<0.5)) {
        cout<<0;
        return 0;
    }
     double c1 = x*vx+y*vy + sqrt((x*vx + y*vy)*(x*vx + y*vy) + (x*x+y*y)*(vmax*vmax-vx*vx-vy*vy));
     double c2 = x*wx+y*wy + sqrt((x*wx + y*wy)*(x*wx + y*wy) + (x*x+y*y)*(vmax*vmax-wx*wx-wy*wy));
    c1 /= x*x+y*y;
    c2 /= x*x+y*y;
    if(c1*t >= 1) {
        ans = 1./c1;
        printf("%.10lf", ans);
    }
    else {
        ans = t;
        x -= vx*t;
        y -= vy*t;
         double sum = sqrt(x*x+y*y);
        //long double sx = vmax * x/sum;
        //long double sy = vmax * y/sum;
        //cout<<sx*sx+sy*sy<<endl;
        //sx+=wx; sy+=wy;
         double A=vmax*vmax - wx*wx-wy*wy;
         double B=t*vmax*vmax + x*wx+y*wy;
         double C = vmax*vmax*t*t - x*x-y*y;
        ans+= (-B + sqrt(B*B - A*C))/A;
        printf("%.10lf", ans);
    }
    
    
    //for(int i=0; i<n; i++) 
    
}