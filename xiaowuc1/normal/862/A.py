n, k = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
ret = 0
curr = 0
while curr < k:
    if curr not in l:
        ret += 1
    curr += 1
if k in l:
    ret += 1
print ret