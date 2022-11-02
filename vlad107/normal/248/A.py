n=int(input())
a,b=zip(*[map(int,raw_input().split()) for _ in range(n)])
print min(sum(a),n-sum(a))+min(sum(b),n-sum(b))