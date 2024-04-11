{$r-,q-,s-,i-,o+}
const 
  base=51123987;
  
var
  nn,res,na,nb,nc,n,i,m,a,b,c:longint;
  f:array[0..155,0..55,0..55,0..55]of longint;
  next:array[0..155,'a'..'c']of longint;
  s,p:ansistring;
  
  procedure upd(var x:longint;val:longint);
    begin
      inc(x,val);
      if (x>=base)then dec(x,base);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n);
  readln(s);
  p:=s[1];
  for i:=2 to length(s)do
    if (s[i]<>p[length(p)])then p:=p+s[i];    
  m:=length(p);
  next[m+1]['a']:=-1;
  next[m+1]['b']:=-1;
  next[m+1]['c']:=-1;
  for i:=m downto 1 do begin
    next[i]:=next[i+1];
    next[i][p[i]]:=i;
  end;
  fillchar(f,sizeof(f),$0);
  f[1][0][0][0]:=1;
  for i:=1 to m do begin
    for a:=0 to n do if (a<=53)then
      for b:=0 to n-a do if (b<=53)then
        for c:=0 to n-a-b do if (c<=53)then
          if (f[i][a][b][c]<>0)then begin
            nn:=next[i]['a'];
            if (nn<>-1)then upd(f[nn][a+1][b][c],f[i][a][b][c]);

            nn:=next[i]['b'];
            if (nn<>-1)then upd(f[nn][a][b+1][c],f[i][a][b][c]);

            nn:=next[i]['c'];
            if (nn<>-1)then upd(f[nn][a][b][c+1],f[i][a][b][c]);
          end;
  end;
  res:=0;
  for i:=1 to m do 
    for a:=0 to n do 
      for b:=0 to n-a do begin
        c:=n-a-b;
        if (abs(a-b)>1)then continue;
        if (abs(a-c)>1)then continue;
        if (abs(b-c)>1)then continue;
        upd(res,f[i][a][b][c]);
      end;
  writeln(res);
end.