n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]
sa=sorted(a)

if len(sa)>1:
    sa=sa[:n-n/2]
print sa[-1]