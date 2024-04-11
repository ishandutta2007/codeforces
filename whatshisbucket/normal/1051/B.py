x=input()
x=x.split()
a=int(x[0])
b=int(x[1])
print("YES")
for i in range(a,b):
    if (i-a)%2==0:
        print(str(i)+" "+str(i+1))