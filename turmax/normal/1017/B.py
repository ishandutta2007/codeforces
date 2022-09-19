n=int(input())
a=str(input())
b=str(input())
m=[0,0,0,0]
for i in range(0,n):
    m[int(a[i])+2*int(b[i])]+=1
print(m[0]*m[1]+m[0]*m[3]+m[1]*m[2])