n=int(input())
a=list(map(int,input().split()))
print("Bob" if a.count(min(a))>n//2 else "Alice")