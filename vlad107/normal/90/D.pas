{$r-,q-,s-,i-,o+}
var
  xs,ys:array[0..555]of int64;
  border,spacing,ty:array[0..555]of longint;
  ss:array[0..555]of string;
  g:array[0..555,0..555]of longint;
  was:array[0..555]of boolean;
  j,ii,jj,kh,i,n:longint;
  tmp:int64;
  q,s:string;
  procedure dfs(x:longint);
    var
      i,kol:longint;
    begin
      if (ty[x]=1)or(was[x])then exit;
      was[x]:=true;
      kol:=0;
      for i:=1 to kh do 
        if (g[x][i]<>0)then begin
          dfs(i);
          inc(kol,g[x][i]);
          if (ty[x]=2)then begin
            xs[x]:=xs[x]+xs[i]*g[x][i];
            if (ys[i]>ys[x])then ys[x]:=ys[i];
          end else begin
            ys[x]:=ys[x]+ys[i]*g[x][i];
            if (xs[i]>xs[x])then xs[x]:=xs[i];
          end;
        end;
      if (kol<>0)then begin
        xs[x]:=xs[x]+2*border[x];
        ys[x]:=ys[x]+2*border[x];
        if (ty[x]=2)
          then xs[x]:=xs[x]+(kol-1)*spacing[x] 
          else ys[x]:=ys[x]+(kol-1)*spacing[x];
      end;
    end;
begin
  readln(n);
  kh:=0;
  fillchar(spacing,sizeof(spacing),$0);
  fillchar(border,sizeof(border),$0);
  fillchar(g,sizeof(g),$0);
  for i:=1 to n do begin
    readln(s);
    q:=copy(s,1,pos(' ',s)-1);
    if (q='Widget')
      then begin
        delete(s,1,pos(' ',s));
        inc(kh);
        ss[kh]:=copy(s,1,pos('(',s)-1);
        delete(s,1,pos('(',s));
        ty[kh]:=1;
        val(copy(s,1,pos(',',s)-1),xs[kh]);
        delete(s,1,pos(',',s));
        val(copy(s,1,pos(')',s)-1),ys[kh]);
        continue;
      end;
    if (q='VBox')or(q='HBox')then begin
      delete(s,1,pos(' ',s));
      inc(kh);
      ss[kh]:=s;
      if (q='HBox')then ty[kh]:=2 else ty[kh]:=3;
      xs[kh]:=0;
      ys[kh]:=0;
      continue;
    end;
    q:=copy(s,1,pos('.',s)-1);
    ii:=1;
    while (ss[ii]<>q)do inc(ii);
    delete(s,1,pos('.',s));
    if (s[1]='p')then begin
      delete(s,1,5);
      delete(s,length(s),1);
      jj:=1;
      while (ss[jj]<>s)do inc(jj);
      inc(g[ii][jj]);
      continue;
    end;
    if (s[5]='b')then begin
      delete(s,1,pos('(',s));
      val(copy(s,1,pos(')',s)-1),border[ii]);
    end else begin
      delete(s,1,pos('(',s));
      val(copy(s,1,pos(')',s)-1),spacing[ii]);
    end;
  end;
  fillchar(was,sizeof(was),false);
  for i:=1 to kh do 
    if (not was[i])then dfs(i);
  for i:=1 to kh-1 do 
    for j:=1 to kh-1 do 
      if (ss[j]>ss[j+1])then begin
        s:=ss[j];ss[j]:=ss[j+1];ss[j+1]:=s;
        tmp:=xs[j];xs[j]:=xs[j+1];xs[j+1]:=tmp;
        tmp:=ys[j];ys[j]:=ys[j+1];ys[j+1]:=tmp;
      end;
  for i:=1 to kh do writeln(ss[i],' ',xs[i],' ',ys[i]);
end.