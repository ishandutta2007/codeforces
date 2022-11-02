{$r-,q-,s-,i-,o+}
var
  ans,b,d,i,j,ls,lp,q,nt,lt:longint;
  ks:array[#0..#255]of longint;
  next:array[0..1111,0..333]of longint;
  len:array[0..1111,0..333]of int64;
  lw:array[0..500500]of int64;
  nw:array[0..500500]of longint;
  s,p:ansistring;

begin
  readln(b,d);
  readln(s);
  readln(p);
  fillchar(ks,sizeof(ks),$0);
  for i:=1 to length(s)do inc(ks[s[i]]);
  for i:=1 to length(p)do 
    if (ks[p[i]]=0)then begin
      writeln(0);
      exit;
    end;
  ls:=length(s);
  lp:=length(p);
  for i:=1 to ls do begin
    j:=i;lt:=0;
    for q:=1 to lp do begin
      while (s[j]<>p[q])do begin
        inc(lt);
        inc(j);
        if (j>ls)then j:=1;
      end;
      inc(j);
      if (j>ls)then j:=1;
      inc(lt);
      next[i][0]:=j;
      len[i][0]:=lt;
    end;
  end;
  for j:=1 to 30 do 
    for i:=1 to ls do begin
      next[i][j]:=next[next[i][j-1]][j-1];
      len[i][j]:=len[i][j-1]+len[next[i][j-1]][j-1];
    end;
  for i:=1 to ls do begin
    q:=d;
    lt:=0;nt:=i;
    for j:=30 downto 0 do 
      if (1 shl j<=q)then begin
        dec(q,1 shl j);
        lt:=lt+len[nt][j];
        nt:=next[nt][j];
      end;
    nw[i]:=nt;
    lw[i]:=lt;
  end;
  for i:=1 to ls do begin
    next[i][0]:=nw[i];
    len[i][0]:=lw[i];
  end;  
  for j:=1 to 30 do 
    for i:=1 to ls do begin
      next[i][j]:=next[next[i][j-1]][j-1];
      len[i][j]:=len[i][j-1]+len[next[i][j-1]][j-1];
    end;
  lt:=0;nt:=1;
  ans:=0;
  for j:=30 downto 0 do 
    if (lt+len[nt][j]<=ls*b)then begin
      lt:=lt+len[nt][j];
      nt:=next[nt][j];
      inc(ans,1 shl j);
    end;
  writeln(ans);
end.