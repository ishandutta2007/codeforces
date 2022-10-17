d=input()
n=input()-1
a=map(int,raw_input().split())
print n*d-sum(a)+a[-1]