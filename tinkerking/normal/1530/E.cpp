#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[100010];
int cnt[26];
int n;
typedef pair<char, int> pci;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s + 1);
        n = strlen(s + 1);
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            cnt[s[i] - 'a']++;
        }
        vector<pci>fuck;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                fuck.push_back(pci('a' + i, cnt[i]));
                //printf("%c %d\n",'a' + i, cnt[i]);
            }
        }
        int M = fuck.size();
        int first_1 = -1;
        for (int i = 0; i < M; i++) {
            if (fuck[i].second == 1) {
                first_1 = i;
                break;
            }
        }
        if (first_1 != -1) {
            string ans = "";
            ans += fuck[first_1].first;
            for (int i = 0; i < M; i++) {
                if (i == first_1) continue;
                for (int j = 0; j < fuck[i].second; j++) ans += fuck[i].first;
            }
            printf("%s\n",ans.c_str());
            continue;
        }
        if (M == 1) {
            string ans = "";
            for (int i = 0; i < fuck[0].second; i++) {
                ans += fuck[0].first;
            }
            printf("%s\n",ans.c_str());
            continue;
        }
        if (M == 2) {
            string ans = "";
            int cnta = fuck[0].second, cntb = fuck[1].second;
            char ca = fuck[0].first, cb = fuck[1].first;
            if (cnta >= 2 && cntb >= cnta - 2) {
                ans += ca;
                ans += ca;
                cnta -= 2;
                for (int i = 1; i <= cnta; i++) {
                    ans += cb;
                    ans += ca;
                }
                cntb -= cnta;
                for (int i = 1; i <= cntb; i++) ans += cb;
            } else {
                ans += ca;
                for (int i = 1; i <= cntb; i++) ans += cb;
                for (int i = 1; i <= cnta - 1; i++) ans += ca; 
            }
            printf("%s\n",ans.c_str());
            continue;
        } 
        int cnta = fuck[0].second;
        string ans = "";
        int node = 1;
        if (cnta - 2 <= (n - 2) / 2) {
            ans += fuck[0].first;
            ans += fuck[0].first;
            cnta -= 2;
            while(cnta) {
                while(node < M && fuck[node].second == 0) node++;
                cnta--;
                fuck[node].second--;
                ans += fuck[node].first;
                ans += fuck[0].first;
            }
            for (int i = node; i < M; i++) {
                for (int j = 0; j < fuck[i].second; j++) {
                    ans += fuck[i].first;
                }
            }
        } else {
            ans += fuck[0].first;
            cnta--;
            ans += fuck[1].first;
            fuck[1].second--;
            for (int i = 0; i < cnta; i++) ans += fuck[0].first;
            ans += fuck[2].first;
            fuck[2].second--;
            for (int i = 1; i < M; i++) {
                for (int j = 0; j < fuck[i].second; j++) {
                    ans += fuck[i].first;
                }
            }
        }
        printf("%s\n",ans.c_str());
    }
}