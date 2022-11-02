n=input()
a=map(int,raw_input().split())
print len(filter(lambda x:(sum(a)+x+1)%(n+1)!=1,range(5)))