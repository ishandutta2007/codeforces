#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[100500];
ll cons[1555];
string s[100500];
struct HashSet {
    string key[9000000];
    int val[9000000];
   int getHash(string x) {
       int ans = 0;
       for (int i = 0; i < x.size(); i++)
            ans = ((ans*timer+x[i]-'0'+1)&((1<<23)-1));
        return ans;
   }
   void add(string x, int vl) {
       int hsh = getHash(x);
       while (key[hsh] != x && key[hsh] != "")
            hsh++;
        if (key[hsh] == "")
            key[hsh] = x, val[hsh] = vl;
        else
            val[hsh] += vl;
   }
   int get(string x) {
       int hsh = getHash(x);
       while (key[hsh] != x && key[hsh] != "")
            hsh++;
        if (key[hsh] == "")
            return 0;
        return val[hsh];
   }
} f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;

    srand(time(0));
    timer = rand()%30+35;
    //n = 70000;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        //for (j = 0; j < 9; j++)
        //    s[i].push_back(rand()%10+'0');
        for (j = 1; j <= 9; j++)
            for (k = 0; k+j <= 9; k++)
            {
                string s1 = s[i].substr(k,j);
                f.add(s1, 1);
            }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= 9; j++)
            for (k = 0; k+j <= 9; k++)
            {
                string s1 = s[i].substr(k,j);

                f.add(s1, -1);
            }
        int flag = 0;
        for (j = 1; j <= 9; j++)
        {
            for (k = 0; k+j <= 9; k++)
            {
                string s1 = s[i].substr(k,j);
                if (f.get(s1) == 0)
                {
                    flag = 1;
                    cout << s1 << endl;
                    break;
                }
            }
            if (flag)
                break;
        }
        for (j = 1; j <= 9; j++)
            for (k = 0; k+j <= 9; k++)
            {
                string s1 = s[i].substr(k,j);
                f.add(s1, 1);
            }
    }
    return 0;
}