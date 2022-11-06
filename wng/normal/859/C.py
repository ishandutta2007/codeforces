n=int(raw_input())
t=[int(k) for k in raw_input().split(" ")]

d=0
nd=0

for k in t[::-1]:
    if k+nd>=d:
        newnd=d
        d=k+nd
        nd=newnd
    else:
        nd=nd+k

   
print nd,d