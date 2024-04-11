#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cassert>
#include<ctime>

#define X first
#define Y second

using namespace std;
typedef long long lint;

typedef pair<lint, char> sym;

vector<sym> s, t, p;
vector<int> z;
int n, m;
lint ans = 0ll;

char myget(){
    char res = '!';
    while(!(res >= 'a' && res <= 'z'))
        res = getc(stdin);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &m, &n);
    s.resize(n); t.resize(m);
    int last = -1;
    for(int i = 0; i < m; i++){
        int cnt;
        scanf("%d", &cnt);
        char c = myget();
        if(last != -1 && t[last].Y == c){
            t[last].X += cnt;
        }
        else{
            last++;
            t[last] = make_pair(cnt, c);
        }
    }
    m = last + 1;
    last = -1;
    for(int i = 0; i < n; i++){
        int cnt;
        scanf("%d", &cnt);
        char c = myget();
        if(last != -1 && s[last].Y == c){
            s[last].X += cnt;
        }
        else{
            last++;
            s[last] = make_pair(cnt, c);
        }
    }
    n = last + 1;
    if(n == 1){
        for(int i = 0; i < m; i++){
            if(s[0].Y == t[i].Y){
               ans += max(0ll, t[i].X - s[0].X + 1ll);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(n == 2){
        for(int i = 1; i < m; i++){
            if(s[0].Y == t[i - 1].Y && s[1].Y == t[i].Y && s[0].X <= t[i - 1].X && s[1].X <= t[i].X)
                ans++;
        }
        cout << ans << endl;
        return 0;
    }
    p.resize(n - 2 + 1 + m);
    z.resize(n - 2 + 1 + m);
    int cp = 0;
    for(int i = 1; i < n - 1; i++){
        p[cp] = s[i];
        cp++;
    }
    sym dvr = make_pair(0, '#');
    p[cp] = dvr; cp++;
    for(int i = 0; i < m; i++){
        p[cp] = t[i];
        cp++;
    }
    for (int i=1, l=0, r=0; i < n - 2 + 1 + m; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n - 2 + 1 + m && p[z[i]] == p[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	for(int i = n - 2 + 1; i < n - 2 + 1 + m; i++){
        if(z[i] < n - 2)
            continue;
        if(i == 0 || p[i - 1].Y != s[0].Y || p[i - 1].X < s[0].X)
            continue;
        if(i + n - 2 >=  n - 2 + 1 + m || p[i + n - 2].Y != s[n - 1].Y || p[i + n - 2].X < s[n - 1].X)
            continue;
        ans++;
	}
	cout << ans << endl;
    return 0;
}