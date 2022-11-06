
n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]
sa=sorted(a)
if n%2:
    print sa[n/2]
else:
    print sa[n/2-1]