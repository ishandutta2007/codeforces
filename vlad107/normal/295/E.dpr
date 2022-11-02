{$r-,q-,s-,i-,o+}
type
  TPoint=record
    kol,left,right,x,y,min,max:longint;
    ans,sum:int64;
  end;

var
  lll,llr,qt,x,y,kt,i,n,ll,rr,rt,tt:longint;
  a:array[0..500500]of longint;
  tr:array[0..500500]of TPoint;
  
  function create(x:longint):longint;
    begin
      inc(kt);
      tr[kt].kol:=1;
      tr[kt].left:=0;
      tr[kt].right:=0;
      tr[kt].x:=x;
      tr[kt].y:=random(maxlongint);
      tr[kt].min:=x;
      tr[kt].max:=x;
      tr[kt].sum:=x;
      tr[kt].ans:=0;
      create:=kt;
    end;

  function updd(u,l,r:TPoint):TPoint;
    begin
      if (l.max=maxlongint)then begin l.sum:=0;l.ans:=0;l.min:=0;l.kol:=0;end;
      if (r.max=maxlongint)then begin r.sum:=0;r.ans:=0;r.min:=0;r.kol:=0; end;
      u.sum:=l.sum+r.sum+u.x;
      u.kol:=l.kol+r.kol+1;
      u.ans:=r.sum*(l.kol+1)-(l.sum+u.x)*r.kol+l.ans+r.ans+int64(u.x)*l.kol-l.sum;
      u.min:=u.x;u.max:=u.x;
      if (l.max<>maxlongint)then u.min:=l.min;
      if (r.max<>maxlongint)then u.max:=r.max;
      updd:=u;
    end;
  
  procedure upd(u:longint);
    begin
      if (u=0)then exit;
      tr[u]:=updd(tr[u],tr[tr[u].left],tr[tr[u].right]);
    end;
    
  
  function merge(lt,rt:longint):longint;
    begin
      if (lt=0)or(rt=0)then begin merge:=lt+rt;exit; end;
      if (tr[lt].y>tr[rt].y)then begin
        tr[lt].right:=merge(tr[lt].right,rt);
        upd(lt);
        merge:=lt;
      end else begin
        tr[rt].left:=merge(lt,tr[rt].left);
        upd(rt);
        merge:=rt;
      end;
    end;
    
  procedure split(u,x:longint;var lt,rt:longint);
    begin
      if (u=0)then begin lt:=0;rt:=0;exit; end;
      if (x<tr[u].min)then begin lt:=0;rt:=u;exit; end;
      if (x>tr[u].max)then begin lt:=u;rt:=0;exit; end;
      if (tr[u].x<=x)then begin
        split(tr[u].right,x,lt,rt);
        tr[u].right:=lt;
        upd(u);
        lt:=u;
      end else begin
        split(tr[u].left,x,lt,rt);
        tr[u].left:=rt;
        upd(u);
        rt:=u;
      end;
    end;
    
  function find(u,l,r:longint):TPoint;
    var
      res:TPoint;
    begin
      if (u=0)or(r<tr[u].min)or(l>tr[u].max)then begin
        res.max:=maxlongint;
        res.ans:=0;
        find:=res;
      end else
      if (l<=tr[u].min)and(r>=tr[u].max)then find:=tr[u]else
      if (r<tr[u].x)then find:=find(tr[u].left,l,r)else
      if (l>tr[u].x)then find:=find(tr[u].right,l,r)else begin
        res.sum:=tr[u].x;
        res.ans:=0;
        res.x:=tr[u].x;
        find:=updd(res,find(tr[u].left,l,r),find(tr[u].right,l,r));
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  randseed:=51235;
  read(n);
  rt:=0;
  tr[0].max:=maxlongint;
  for i:=1 to n do begin
    read(a[i]);
    split(rt,a[i],ll,rr);
    rt:=merge(merge(ll,create(a[i])),rr);
  end;
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(qt,x,y);
    if (qt=1)then begin
      split(rt,a[x],ll,rr);
      split(ll,a[x]-1,lll,llr);
      rt:=merge(lll,rr);
      a[x]:=a[x]+y;
      split(rt,a[x],ll,rr);
      rt:=merge(merge(ll,create(a[x])),rr);
    end else writeln(find(rt,x,y).ans);
  end;
end.