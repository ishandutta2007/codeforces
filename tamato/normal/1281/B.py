from collections import defaultdict
import sys
input = sys.stdin.readline


t = int(input())
for _ in range(t):
    s, c = input().split()
    N = len(s)
    s_list = [(ord(s[i]), i) for i in range(N)]
    s_list_set = list(set([ord(si) for si in s]))
    s_list_set.sort()
    val2idx = {s_list_set[i]: i for i in range(len(s_list_set))}
    s_list_cmpr = [0] * N
    for i in range(N):
        s_list_cmpr[s_list[i][1]] = val2idx[s_list[i][0]]

    idx = defaultdict(list)
    for i in range(N):
        idx[s_list_cmpr[i]].append(i)

    k = 0
    i1 = i2 = 0
    for i in range(N):
        if s_list_cmpr[i] == k:
            continue
        elif s_list_cmpr[i] == k + 1:
            if idx[k][-1] == i-1:
                k += 1
            else:
                i1 = i
                i2 = idx[k][-1]
                break
        else:
            while idx[k][-1] <= i:
                k += 1
            i1 = i
            i2 = idx[k][-1]
            break
    s_list_raw = [ord(si) for si in s]
    s_list_raw[i1], s_list_raw[i2] = s_list_raw[i2], s_list_raw[i1]
    ans = ''.join([chr(x) for x in s_list_raw])
    if ans < c:
        print(ans)
    else:
        print('---')