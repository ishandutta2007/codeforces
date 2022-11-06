n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

d=set()
ladded=0
for k in range(len(a)-1,-1,-1):
    if a[k] not in d:
        d.add(a[k])
        ladded=a[k]
print ladded