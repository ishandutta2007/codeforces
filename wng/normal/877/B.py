#[int(k) for k in raw_input().split(" ")]
import string
s=raw_input()

c1,c2,c3=0,0,0

for k in s:
    if k=="a":
        c1+=1
        c3=max(c3,c2)+1
    else:
        c2=max(c2,c1)+1
   # print k,c1,c2,c3

print max(c2,max(c1,c3))