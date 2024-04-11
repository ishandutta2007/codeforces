n=int(input())
print ["\n".join("\n".join("".join("w" if ((k+i/2+j/2)%2==0) else "b" for j in range(n)) for i in range(n))+"\n" for k in range(n)),-1][n%2]