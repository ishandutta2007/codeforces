n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]

divs=[[0,0] for k in range(n)]

for i in range(n):
    b=a[i]
    while not b%2:
        b/=2
        divs[i][0]+=1
    while not b%3:
        b/=3
        divs[i][1]+=1

r=sorted(range(n),key=lambda i:(divs[i][0],-divs[i][1]))

res=" ".join([str(a[i]) for i in r])

print res