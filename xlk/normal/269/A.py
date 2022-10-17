n=input()
z=0
for i in range(n):
    a,b=map(int,raw_input().split())
    if b==1:
        a+=1;
    while b>1:
        a+=1
        b=(b+3)/4
    z=max(z,a)
print z