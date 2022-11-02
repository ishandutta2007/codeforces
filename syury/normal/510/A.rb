n,m=gets.split(" ").map {|x| x.to_i}
i = 1
while i<=n do
  if i%4==0
    print "#"
    j = 2
    while j<=m do
      print "."
      j+=1
    end
  elsif i%4==2
    j=1
    while j<m do
      print "."
      j+=1
    end
    print "#"
  else
    j=1
    while j<=m do
      print "#"
      j+=1
    end
  end
  puts("")
  i+=1
end