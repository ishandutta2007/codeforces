n=int(input())
print(2**29,0)
k=input()
new=2**29
for i in range(n-1):
    if new<=2**29:
        print(2**29,new)
    else:
        print(2**30-new,2**29)
    j=input()
    if j==k:
        new+=2**(28-i)
    else:
        new-=2**(28-i)
if new<=2**29:
    print(0,0,2**29,new)
else:
    print(0,0,2**30-new,2**29)