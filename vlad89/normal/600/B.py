import bisect
n, m = map(int, input().split())
a = map(int, input().split())
b = map(int, input().split())
a = sorted(a)
c = [bisect.bisect_right(a, i) for i in b]
print(' '.join(map(str, c)))