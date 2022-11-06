

n,w=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]

mn=0
mx=0
curr=0

for i in a:
    curr+=i
    if curr<mn:
        mn=curr
    if curr>mx:
        mx=curr

mmx=w-mx
mmn=-mn

print max(0,mmx-mmn+1)