a=input()
a=a.split()
n=int(a[0])
m=int(a[1])
for i in range(n):
    if i%2==0:
        print("#"*m)
    elif (i-1)%4==0:
        print("."*(m-1)+"#")
    else:
        print("#"+"."*(m-1))