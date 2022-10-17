import math;I=lambda:[*map(int,input().split())]
for _ in[0]*I()[0]:n,k=I();l=sorted(I());print(math.comb(l.count(l[-k]),l[-k:].count(l[-k]))%(10**9+7))