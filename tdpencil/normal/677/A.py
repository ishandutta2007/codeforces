friends, height = [int(i) for i in input().split()]

l=input().split()
c=0
for i in l:
    if int(i) > height:
        c+=2
    else:
        c+=1
print(c)