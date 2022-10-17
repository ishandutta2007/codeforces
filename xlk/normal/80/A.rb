require'prime'
x,y=gets.split.map &:to_i
puts Prime.find{|_|_>x}==y ?:YES:"NO"