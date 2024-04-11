x=input()
x=x.split()
y=input()
y=y.split()
sum=0
for guy in y:
    if int(guy)>int(x[1]):
        sum+=2
    else:
        sum+=1
print(sum)