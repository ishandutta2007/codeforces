n = gets.to_i
i = 1
s = 1
while s<=n do
  if s==n
    print "YES"
    exit
  end
  i+=1
  s=i*(i+1)/2
end
print "NO"