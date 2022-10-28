n=int(input())
for i in range(n):
    bars=0
    x=input()
    x=x.split()
    bought=int(x[0])//int(x[3])
    bars+=bought
    bars+=(bought//int(x[1]))*int(x[2])
    print(bars)