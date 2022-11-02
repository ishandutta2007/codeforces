n=int(input())
a=map(int,raw_input().split())
x=min(a)
print [x,-1][min(1,sum(map(lambda t:t%x,a)))]