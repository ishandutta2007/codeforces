n,k=map(int,raw_input().split())
a=map(lambda t:1 if t=='.' else 0,raw_input())
l=0
for i in range(1,n):
    if (l+k>=i)and(a[i]==1):
        l=i
print ["YES","NO"][l<n-1]