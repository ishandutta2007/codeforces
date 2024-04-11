var
  cr,res,i,j,n,m:longint;
  ch:char;
  s:array[1..15]of string;
  ks,a:array[1..15]of longint;
  p:string;
  procedure rec(x,k:longint);
    begin
      if (k=ks[1])then begin
        p:=s[1];
        for i:=1 to ks[1] do 
          if (p[a[i]]='0')
            then p[a[i]]:='1'
            else p[a[i]]:='0';
        inc(res);
        for i:=2 to m do begin
          cr:=ks[i];
          for j:=1 to n do 
            if (p[j]<>s[i][j])then dec(cr);
          if (cr<>0)then begin
            dec(res);
            break;
          end;
        end;
        exit;
      end;
      if (x>n)then exit;
      rec(x+1,k);
      a[k+1]:=x;
      rec(x+1,k+1);
    end;
begin
  readln(n,m);
  for i:=1 to m do begin
    s[i]:='';
    for j:=1 to n do begin
      read(ch);
      s[i]:=s[i]+ch;
    end;
    readln(ks[i]);
  end;
  res:=0;
  rec(1,0);
  writeln(res);
end.