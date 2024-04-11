n, k = (int(x) for x in raw_input().split())
ret = 1
if k >= 2:
    ret += n*(n-1)/2
if k >= 3:
    ret += n*(n-1)*(n-2)/3
if k >= 4:
    ret += n*(n-1)*(n-2)*(n-3)/8
    ret += n*(n-1)*(n-2)*(n-3)/4
print ret