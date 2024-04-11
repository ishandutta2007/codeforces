def main():
    n=int(input())
    a=input()
    b=input()
    last=None
    cost=0
    for i in range(n):
        if a[i]!=b[i]:
            if last is None:
                cost+=1
                last=a[i]
            elif a[i]==last:
                cost+=1
            else:
                last=None
            
        else:
            last=None
    print(cost)
main()