import sys
from collections import defaultdict
input = sys.stdin.buffer.readline

t = int(input())
for _ in range(t):
    N = int(input())
    a = list(map(int, input().split()))

    dic = defaultdict(int)
    for x in a:
        cnt = 0
        while x % 2 == 0:
            x //= 2
            cnt += 1
        dic[x] = max(dic[x], cnt)
    print(sum(list(dic.values())))