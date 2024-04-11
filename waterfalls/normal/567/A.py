from sys import stdout
n = int(input())
x = [int(y) for y in input().split()]
stdout.write(str(x[1]-x[0])+" "+str(x[n-1]-x[0])+"\n")
for i in range(1,n-1):
    stdout.write(str(min(x[i+1]-x[i],x[i]-x[i-1]))+" "+str(max(x[n-1]-x[i],x[i]-x[0]))+"\n")
stdout.write(str(x[n-1]-x[n-2])+" "+str(x[n-1]-x[0])+"\n")