n=[int(k) for k in raw_input().split(" ")][0]

p=0
while n:
    n=n-(n-1)/2-1
    p+=1
print p