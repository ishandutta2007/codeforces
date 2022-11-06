n,k=[int(k) for k in raw_input().split(" ")]
a=[int(kk) for kk in raw_input().split(" ")]

ms=-1000
for i in range(k):
    ms=max(ms,abs(sum([a[j] for j in range(n) if j%k!=i])))

print ms