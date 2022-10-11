a, b, c = (int(x) for x in raw_input().split())
print min(2*(a+b+c-max(a,b,c)), a+b+c,)