import sys
from collections import defaultdict
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    dic = defaultdict(int)
    ans = 0
    for i in range(d):
        if dic[a[i]] == 0:
            ans += 1
        dic[a[i]] += 1
    ans_min = ans
    for i in range(n - d):
        if dic[a[i]] == 1:
            ans -= 1
        dic[a[i]] -= 1
        if dic[a[i + d]] == 0:
            ans += 1
        dic[a[i + d]] += 1
        ans_min = min(ans, ans_min)
    print(ans_min)