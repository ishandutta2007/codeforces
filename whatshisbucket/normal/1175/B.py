l=int(input())
b=float("inf")
curr=[]
leng=0
tot=0
prod=1
lim=None
save=None
k=2**32-1
for i in range(l):
    if tot==b:
        print("OVERFLOW!!!")
        exit()
    a=input().split()
    if a[0]=="add":
        tot+=prod
    elif a[0]=="end":
        if lim is None:
            prod//=curr[-1]
            curr.pop()
            leng-=1
        else:
            curr.pop()
            leng-=1
            if leng==lim:
                prod=save
                lim=None
    else:
        curr.append(int(a[1]))
        leng+=1
        prod*=int(a[1])
        if prod>k and prod!=b:
            save=prod//int(a[1])
            prod=b
            lim=leng-1
if tot>k:
    print("OVERFLOW!!!")
else:
    print(tot)