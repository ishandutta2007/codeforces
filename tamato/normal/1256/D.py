from collections import deque
import sys
input = sys.stdin.readline

q = int(input())
for _ in range(q):
    n, k = map(int, input().split())
    s = input()
    ans = deque()
    cnt = 0
    flg = 1
    for i in range(n):
        if flg:
            if s[i] == '0':
                if i - cnt <= k:
                    ans.appendleft(0)
                    k -= i - cnt
                    cnt += 1
                else:
                    flg = 0
                    j = i - k
            else:
                ans.append(1)
        else:
            ans.append(int(s[i]))
    if flg:
        print(''.join(map(str, ans)))
    else:
        ans = list(ans)
        ans1 = ans[:j]
        ans2 = ans[j:]
        print(''.join(map(str, ans1)) + '0' + ''.join(map(str, ans2)))