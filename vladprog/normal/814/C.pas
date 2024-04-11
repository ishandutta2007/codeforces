{$macro+}
{$define free}

{$ifdef free}
uses math;
{$endif}

var
  n,l,r,i,m,ans,lc,rc,q:longint;
  s:array[-1500..1500]of char;
  c:char;
  res:array[1..1500,'a'..'z']of longint;

begin
  readln(n);
  for i:=-n to 0 do s[i]:=' ';
  for i:=1 to n do read(s[i]);
  for m:=1 to n do
    for c:='a' to 'z' do
      begin
        l:=-m;
        lc:=-m;
        rc:=-1;
        r:=-1;
        ans:=m;
        while r<n do
          begin
            inc(lc);
            l:=lc;
            while (lc<n)and(s[lc]=c) do inc(lc);
            inc(r);
            rc:=r;
            while (r<n)and(s[r+1]=c) do inc(r);
            ans:=max(ans,r-l+1)
          end;
        res[m,c]:=min(ans,n)
      end;
  read(q);
  for i:=1 to q do
    begin
      read(m,c,c);
      writeln(res[m,c])
    end
end.