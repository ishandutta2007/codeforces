import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    cnt = {}
    cnt1 = [0] * 26
    cnt2 = [0] * 26
    for i in range(n):
        s = input()
        if s not in cnt.keys():
            cnt[s] = 0
        cnt[s] += 1
        cnt1[ord(s[0]) - ord('a')] += 1
        cnt2[ord(s[1]) - ord('a')] += 1
    ans = 0
    for i in range(26):
        ans += cnt1[i] * (cnt1[i] - 1) // 2
        ans += cnt2[i] * (cnt2[i] - 1) // 2
    for i in cnt.values():
        ans -= i * (i - 1)
    print(ans)